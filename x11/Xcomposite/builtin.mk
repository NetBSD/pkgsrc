# $NetBSD: builtin.mk,v 1.8 2005/06/03 17:02:36 jlam Exp $

BUILTIN_PKG:=	Xcomposite

BUILTIN_FIND_FILES_VAR:=		H_XCOMPOSITE
BUILTIN_FIND_FILES.H_XCOMPOSITE=	\
	${X11BASE}/include/X11/extensions/xcomposite.h

.include "../../mk/buildlink3/bsd.builtin.mk"

###
### Determine if there is a built-in implementation of the package and
### set IS_BUILTIN.<pkg> appropriately ("yes" or "no").
###
.if !defined(IS_BUILTIN.Xcomposite)
IS_BUILTIN.Xcomposite=	no
.  if exists(${H_XCOMPOSITE})
PKGSRC_USE_TOOLS+=	imake			# XXX
IMAKE?=			${X11BASE}/bin/imake	# XXX
_BUILTIN_IMAKE_CMD=	${IMAKE:C/^/_asdf_/1:M_asdf_*:S/^_asdf_//}
.    if exists(${_BUILTIN_IMAKE_CMD})
IS_BUILTIN.Xcomposite!=							\
	dir=`cd ${BUILDLINK_PKGSRCDIR.Xcomposite} && ${PWD_CMD}`;	\
	cd ${TMPDIR:U/tmp:Q} && 					\
	${IMAKE} -DUseInstalled -I${X11BASE}/lib/X11/config		\
		-f $$dir/builtin-imake.mk -C builtin-imake.$$$$.c	\
		-s - |							\
	${IMAKE_MAKE} -f - builtin-test
.    endif
.  endif
.endif
MAKEVARS+=	IS_BUILTIN.Xcomposite

###
### Determine whether we should use the built-in implementation if it
### exists, and set USE_BUILTIN.<pkg> appropriate ("yes" or "no").
###
.if !defined(USE_BUILTIN.Xcomposite)
.  if ${PREFER.Xcomposite} == "pkgsrc"
USE_BUILTIN.Xcomposite=	no
.  else
USE_BUILTIN.Xcomposite=	${IS_BUILTIN.Xcomposite}
.    if defined(BUILTIN_PKG.Xcomposite) && \
        !empty(IS_BUILTIN.Xcomposite:M[yY][eE][sS])
USE_BUILTIN.Xcomposite=	yes
.      for _dep_ in ${BUILDLINK_DEPENDS.Xcomposite}
.        if !empty(USE_BUILTIN.Xcomposite:M[yY][eE][sS])
USE_BUILTIN.Xcomposite!=						\
	if ${PKG_ADMIN} pmatch ${_dep_:Q} ${BUILTIN_PKG.Xcomposite:Q}; then \
		${ECHO} yes;						\
	else								\
		${ECHO} no;						\
	fi
.        endif
.      endfor
.    endif
.  endif  # PREFER.Xcomposite
.endif
MAKEVARS+=	USE_BUILTIN.Xcomposite
