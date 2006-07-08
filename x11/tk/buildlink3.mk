# $NetBSD: buildlink3.mk,v 1.21 2006/07/08 23:11:16 jlam Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
TK_BUILDLINK3_MK:=	${TK_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	tk
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ntk}
BUILDLINK_PACKAGES+=	tk
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}tk

.if !empty(TK_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.tk+=	tk>=8.4.6nb1
BUILDLINK_ABI_DEPENDS.tk+=	tk>=8.4.12nb1
BUILDLINK_PKGSRCDIR.tk?=	../../x11/tk

BUILDLINK_FILES.tk+=	bin/wish*
#
# Make "-ltk" and "-ltk8.4" resolve into "-ltk84", so that we don't
# need to patch so many Makefiles.
#
BUILDLINK_TRANSFORM+=	l:tk:tk84
BUILDLINK_TRANSFORM+=	l:tk8.4:tk84

TKCONFIG_SH?=	${BUILDLINK_PREFIX.tk}/lib/tkConfig.sh
.endif	# TK_BUILDLINK3_MK

.include "../../lang/tcl/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
