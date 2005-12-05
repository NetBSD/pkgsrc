# $NetBSD: hacks.mk,v 1.2 2005/12/05 20:51:12 rillig Exp $

# Firefox suffers from display glitches (e.g. text appearing at the wrong
# location) if it was compiled with optimization.

.if ${MACHINE_ARCH} == "powerpc"
.  include "../../mk/compiler.mk"
.  if !empty(CC_VERSION:Mgcc*)
.    if !defined(_GCC_IS_TOO_OLD)
_GCC_IS_TOO_OLD!=	\
	if ${PKG_ADMIN} pmatch 'gcc<4.0' ${CC_VERSION}; then		\
		${ECHO} "yes";						\
	else								\
		${ECHO} "no";						\
	fi
MAKEFLAGS+=	_GCC_IS_TOO_OLD=${_GCC_IS_TOO_OLD:Q}
.    endif
.    if !empty(_GCC_IS_TOO_OLD:M[yY][eE][sS])
PKG_HACKS+=		powerpc-codegen
BUILDLINK_TRANSFORM+=	rm:-O[0-9]*
.    endif
.  endif
.endif
