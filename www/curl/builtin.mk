# $NetBSD: builtin.mk,v 1.1 2006/08/18 12:20:16 adam Exp $

BUILTIN_PKG:=	curl

BUILTIN_FIND_FILES_VAR:=	H_CURL
BUILTIN_FIND_FILES.H_CURL=	/usr/include/curl/curlver.h

.include "../../mk/buildlink3/bsd.builtin.mk"

###
### Determine if there is a built-in implementation of the package and
### set IS_BUILTIN.<pkg> appropriately ("yes" or "no").
###
.if !defined(IS_BUILTIN.curl)
IS_BUILTIN.curl=	no
.  if empty(H_CURL:M__nonexistent__) && empty(H_CURL:M${LOCALBASE}/*)
IS_BUILTIN.curl=	yes
.  endif
.endif
MAKEVARS+=	IS_BUILTIN.curl

###
### If there is a built-in implementation, then set BUILTIN_PKG.<pkg> to
### a package name to represent the built-in package.
###
.if !defined(BUILTIN_PKG.curl) && \
    !empty(IS_BUILTIN.curl:M[yY][eE][sS]) && \
    empty(H_CURL:M__nonexistent__)
BUILTIN_VERSION.curl!=				\
	${AWK} '/\#define[	 ]*LIBCURL_VERSION / {	\
			vers = $$3;			\
			gsub("\"", "", vers);		\
			print vers;			\
		}					\
	' ${H_CURL:Q}
BUILTIN_PKG.curl=	curl-${BUILTIN_VERSION.curl}
.endif
MAKEVARS+=	BUILTIN_PKG.curl

###
### Determine whether we should use the built-in implementation if it
### exists, and set USE_BUILTIN.<pkg> appropriate ("yes" or "no").
###
.if !defined(USE_BUILTIN.curl)
.  if ${PREFER.curl} == "pkgsrc"
USE_BUILTIN.curl=	no
.  else
USE_BUILTIN.curl=	${IS_BUILTIN.curl}
.    if defined(BUILTIN_PKG.curl) && \
        !empty(IS_BUILTIN.curl:M[yY][eE][sS])
USE_BUILTIN.curl=	yes
.      for _dep_ in ${BUILDLINK_API_DEPENDS.curl}
.        if !empty(USE_BUILTIN.curl:M[yY][eE][sS])
USE_BUILTIN.curl!=							\
	if ${PKG_ADMIN} pmatch ${_dep_:Q} ${BUILTIN_PKG.curl:Q}; then \
		${ECHO} yes;						\
	else								\
		${ECHO} no;						\
	fi
.        endif
.      endfor
.    endif
.  endif
.endif
MAKEVARS+=	USE_BUILTIN.curl
