# $NetBSD: hacks.mk,v 1.1 2007/06/21 00:58:04 minskim Exp $

# Disable inline assembly on i386 until GCC Bug #25221 is fixed.
# http://gcc.gnu.org/bugzilla/show_bug.cgi?id=25221
.if !empty(CC_VERSION:Mgcc-4.*)
CONFIGURE_ENV+=	ac_cv_c_inline_asm=no
.endif
