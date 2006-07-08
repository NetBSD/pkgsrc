# $NetBSD: buildlink3.mk,v 1.18 2006/07/08 23:11:12 jlam Exp $
#
# This Makefile fragment is included by packages that use epiphany.
#
# This file was created automatically using createbuildlink-3.1.
#

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
EPIPHANY_BUILDLINK3_MK:=	${EPIPHANY_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	epiphany
.endif

.if !empty(EPIPHANY_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=			epiphany
BUILDLINK_ORDER:=			${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}epiphany
BUILDLINK_API_DEPENDS.epiphany+=		epiphany>=1.8.2
BUILDLINK_ABI_DEPENDS.epiphany?=		epiphany>=2.14.0nb1
BUILDLINK_PKGSRCDIR.epiphany?=		../../www/epiphany

.include "../../mk/bsd.prefs.mk"

.include "../../devel/GConf2/buildlink3.mk"
.include "../../devel/libbonobo/buildlink3.mk"
.include "../../devel/libglade2/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../net/ORBit2/buildlink3.mk"
.include "../../sysutils/gnome-vfs2/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
# XXX: should pull in ../../www/mozilla/gecko-depends.mk
#      this is already pulled in directly by the only user, epiphany-extensions
.endif # EPIPHANY_BUILDLINK3_MK

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
