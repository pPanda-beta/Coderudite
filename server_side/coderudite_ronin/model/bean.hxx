#ifndef BEAN_HXX
#define BEAN_HXX

// Make a FOREACH macro
#define FE_1(WHAT, X) WHAT(X)
#define FE_2(WHAT, X, ...) WHAT(X)FE_1(WHAT, __VA_ARGS__)
#define FE_3(WHAT, X, ...) WHAT(X)FE_2(WHAT, __VA_ARGS__)
#define FE_4(WHAT, X, ...) WHAT(X)FE_3(WHAT, __VA_ARGS__)
#define FE_5(WHAT, X, ...) WHAT(X)FE_4(WHAT, __VA_ARGS__)
//... repeat as needed

#define GET_MACRO(_1,_2,_3,_4,_5,NAME,...) NAME
#define FOR_EACH(action,...) \
  GET_MACRO(__VA_ARGS__,FE_5,FE_4,FE_3,FE_2,FE_1)(action,__VA_ARGS__)

#define DECL_GETTER_OF(Type,Property)  Type get_##Property () const ;
#define DEFN_GETTER_OF(Class, Type, Property)	\
	Type Class :: get_##Property () const		\
	{											\
		return this -> Property	;				\
	}											\


#define DECL_SETTER_OF(Type,Property)  auto set_##Property (const Type &) -> decltype(*this);
#define DEFN_SETTER_OF(Class, Type, Property)				\
	Class & Class :: set_##Property (const Type &value)		\
	{														\
		this -> Property = value;							\
		return *this ;										\
	}														\


#define DECL_GETTER_AND_SETTER_OF(Type, Property)	\
	DECL_GETTER_OF(Type,Property);					\
	DECL_SETTER_OF(Type,Property);					\

#define DEFN_GETTER_AND_SETTER_OF(Class, Type, Property)	\
	DEFN_GETTER_OF(Class, Type, Property);					\
	DEFN_SETTER_OF(Class, Type, Property);					\


#define _DECL_G_S_OF(X)	 DECL_GETTER_AND_SETTER_OF X

#define _DEFN_G_S_OF(X)	 DEFN_GETTER_AND_SETTER_OF X


#define DECL_GETTERS_AND_SETTERS_OF(Args...)		\
	FOR_EACH(_DECL_G_S_OF, Args)

#define DEFN_GETTERS_AND_SETTERS_OF(Args...)		\
	FOR_EACH(_DEFN_G_S_OF, Args)

//Only for Qt - QMetaObject
#define DECL_Q_PROPERTY(Type, Property) Q_PROPERTY( Type Property READ get_##Property WRITE set_##Property )
#define _DECL_Q_P(X)	DECL_Q_PROPERTY X

#define DECL_Q_PROPERTIES(Args...)	\
	FOR_EACH(_DECL_Q_P, Args)

#endif // BEAN_HXX
