# $NetBSD: buildlink3.mk,v 1.5 2004/03/12 21:20:16 jlam Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
GNOME_LIBS_BUILDLINK3_MK:=	${GNOME_LIBS_BUILDLINK3_MK}+

.include "../../mk/bsd.prefs.mk"

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	gnome-libs
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ngnome-libs}
BUILDLINK_PACKAGES+=	gnome-libs

.if !empty(GNOME_LIBS_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.gnome-libs+=		gnome-libs>=1.4.2nb1
BUILDLINK_PKGSRCDIR.gnome-libs?=	../../x11/gnome-libs

.include "../../audio/esound/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../graphics/imlib/buildlink3.mk"
.include "../../graphics/xpm/buildlink3.mk"
.include "../../net/ORBit/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"
.include "../../mk/bdb.buildlink3.mk"

.endif	# GNOME_LIBS_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
