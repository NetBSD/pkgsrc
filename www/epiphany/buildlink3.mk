# $NetBSD: buildlink3.mk,v 1.6 2005/03/22 16:26:14 jmmv Exp $
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
BUILDLINK_DEPENDS.epiphany+=		epiphany>=1.6.0
BUILDLINK_PKGSRCDIR.epiphany?=		../../www/epiphany

.include "../../devel/GConf2/buildlink3.mk"
.include "../../devel/libbonobo/buildlink3.mk"
.include "../../devel/libglade2/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../net/ORBit2/buildlink3.mk"
.include "../../sysutils/gnome-vfs2/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../www/mozilla-gtk2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.endif # EPIPHANY_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
