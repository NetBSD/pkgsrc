# $NetBSD: buildlink3.mk,v 1.2 2004/01/04 23:34:07 jlam Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
TK_BUILDLINK3_MK:=	${TK_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	tk
.endif

.if !empty(TK_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=		tk
BUILDLINK_DEPENDS.tk?=		tk>=8.3.4
BUILDLINK_PKGSRCDIR.tk?=	../../x11/tk

BUILDLINK_FILES.tk=	bin/wish*
#
# Make "-ltk" resolve into "-ltk83", so that we don't need to patch so
# many Makefiles.
#
BUILDLINK_TRANSFORM+=	l:tk:tk83

USE_X11=	YES
TKCONFIG_SH?=	${BUILDLINK_PREFIX.tk}/lib/tkConfig.sh

.  include "../../lang/tcl/buildlink3.mk"
.endif	# TK_BUILDLINK3_MK

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:C/\+$//}
