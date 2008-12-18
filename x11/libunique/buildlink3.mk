# $NetBSD: buildlink3.mk,v 1.1.1.1 2008/12/18 00:32:14 ahoka Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
LIBUNIQUE_BUILDLINK3_MK:=	${LIBUNIQUE_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	libunique
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nlibunique}
BUILDLINK_PACKAGES+=	libunique
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}libunique

.if ${LIBUNIQUE_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.libunique+=	libunique>=1.0.4
BUILDLINK_PKGSRCDIR.libunique?=	../../x11/libunique
.endif	# LIBUNIQUE_BUILDLINK3_MK

pkgbase := libunique
.include "../../mk/pkg-build-options.mk"

.if !empty(PKG_BUILD_OPTIONS.libunique:Mdbus)
.include "../../sysutils/dbus-glib/buildlink3.mk"
.endif

.include "../../x11/gtk2/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
