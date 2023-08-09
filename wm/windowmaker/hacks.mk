# $NetBSD: hacks.mk,v 1.2 2023/08/09 17:46:26 adam Exp $

# Disable inline assembly on i386 until GCC Bug #25221 is fixed.
# http://gcc.gnu.org/bugzilla/show_bug.cgi?id=25221
.if ${CC_VERSION:Mgcc-4.*}
CONFIGURE_ENV+=	ac_cv_c_inline_asm=no
.endif
