# $NetBSD: buildlink3.mk,v 1.7 2026/11/11 11:56:25 wiz Exp $

BUILDLINK_TREE+=	gtkada-25

.if !defined(GTKADA_25_BUILDLINK3_MK)
GTKADA_25_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gtkada-25+=	gtkada-${GNAT_NAME}>=21.0.0
BUILDLINK_ABI_DEPENDS.gtkada-25?=		gtkada-gnat14>=25.2.0nb6
BUILDLINK_PKGSRCDIR.gtkada-25?=		../../x11/ada-gtkada-25
BUILDLINK_DEPMETHOD.gtkada-25?=		build

BUILDLINK_CONTENTS_FILTER.gtkada-25=	\
	${EGREP} "${GNAT_PKGBASE}/include/.*$$|${GNAT_PKGBASE}/lib/.*$$|${GNAT_PKGBASE}/share/gpr/.*$$"

BUILDLINK_FNAME_TRANSFORM.gtkada-25+=	\
	-e "s|${BUILDLINK_DIR}/${GNAT_PKGBASE}/|${BUILDLINK_DIR}/|g"

.include "../../x11/gtk3/buildlink3.mk"

.endif

BUILDLINK_TREE+=	-gtkada-25
