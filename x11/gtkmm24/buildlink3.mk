# $NetBSD: buildlink3.mk,v 1.1.1.1 2004/07/04 13:55:14 drochner Exp $
# XXX
# XXX This file was created automatically using createbuildlink-3.4.
# XXX After this file as been verified as correct, the comment lines
# XXX beginning with "XXX" should be removed.  Please do not commit
# XXX unverified buildlink[23].mk files.
# XXX
# XXX Packages that only install static libraries or headers should
# XXX include the following line:
# XXX
# XXX	BUILDLINK_DEPMETHOD.gtkmm24?=	build

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
GTKMM24_BUILDLINK3_MK:=	${GTKMM24_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	gtkmm24
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ngtkmm24}
BUILDLINK_PACKAGES+=	gtkmm24

.if !empty(GTKMM24_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.gtkmm24+=	gtkmm24>=2.4.4
BUILDLINK_PKGSRCDIR.gtkmm24?=	../../x11/gtkmm24
.endif	# GTKMM24_BUILDLINK3_MK

.include "../../devel/libsigc++2/buildlink3.mk"
.include "../../devel/glibmm24/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
