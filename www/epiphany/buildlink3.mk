# $NetBSD: buildlink3.mk,v 1.7 2005/07/13 09:55:27 drochner Exp $
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

.include "../../mk/bsd.prefs.mk"

.include "../../devel/GConf2/buildlink3.mk"
.include "../../devel/libbonobo/buildlink3.mk"
.include "../../devel/libglade2/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../net/ORBit2/buildlink3.mk"
.include "../../sysutils/gnome-vfs2/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.if ${GECKO_PROVIDER} == "firefox"
.include "../../www/firefox/buildlink3.mk"
.else
.include "../../www/mozilla-gtk2/buildlink3.mk"
.endif
.include "../../x11/gtk2/buildlink3.mk"
.endif # EPIPHANY_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
