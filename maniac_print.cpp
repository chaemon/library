//{{{ print func
#include<iostream>
#include<vector>
#include<string>
#include<type_traits>
#include<utility>
#include<algorithm>

namespace my{
	template<typename T>
		string get_container_name(const T &a){
			const char *c=__PRETTY_FUNCTION__;
			string str(c);
			string::size_type i=str.find("with T = ");
			i+=14;
			string res="";int ct=0;
			while(str[i]!='<' and ct<3)res+=str[i],i++,ct++;
			return res;
		}
	template<typename T>
		struct identity{
			typedef T type;
		};
	template<typename T>
		class is_container{
			template<typename U>
				static true_type check1(U*u,decltype(u->begin())* = nullptr);
			static false_type check1(...);
			template<typename U>
				static true_type check2(U*u,decltype(u->end())* = nullptr);
			static false_type check2(...);
		public:
			static const bool value = identity<decltype(check1((T*)0))>::type::value && identity<decltype(check2((T*)0))>::type::value;
			typedef typename integral_constant<bool,value>::type type;
		};
	template<typename T>
		class is_string:public false_type{
		};
	template<typename CHART,typename TRAITST,typename ALLOCT>
		class is_string<basic_string<CHART,TRAITST,ALLOCT> >:public true_type{
		};
	template<typename T>
		typename enable_if<!my::is_container<T>::value||is_string<T>::value,ostream&>::type print(ostream& stream,const T& t){
			return stream<<t;
		}
	template<typename T>
		typename enable_if<my::is_container<T>::value&&!is_string<T>::value,ostream&>::type print(ostream& stream,const T& container){

			stream<<get_container_name(container)<<"[";
			for(__typeof(container.begin()) it=container.begin();it!=container.end();it++,stream<<((it==container.end())?"":","))print(stream,*it);
			return stream<<"]";
		}
}

template<typename C>
typename enable_if<my::is_container<C>::value&&!my::is_string<C>::value,ostream&>::type operator<<(ostream& stream,const C& c){
	return my::print(stream,c);
}
//}}}
