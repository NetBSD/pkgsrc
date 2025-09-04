# $NetBSD: buildlink3.mk,v 1.1 2025/09/04 13:02:46 dkazankov Exp $

BUILDLINK_TREE+=	adawebserver-25

.if !defined(ADAWEBSERVER_25_BUILDLINK3_MK)
ADAWEBSERVER_25_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.adawebserver-25+=	aws-${GNAT_NAME}>=25.0.0
BUILDLINK_PKGSRCDIR.adawebserver-25?=	../../www/ada-aws-25
BUILDLINK_DEPMETHOD.adawebserver-25?=	build

BUILDLINK_CONTENTS_FILTER.adawebserver-25=	\
	${EGREP} "${GNAT_PKGBASE}/include/.*$$|${GNAT_PKGBASE}/lib/.*$$|${GNAT_PKGBASE}/share/gpr/.*$$"

BUILDLINK_FNAME_TRANSFORM.adawebserver-25+=	\
	-e "s|${BUILDLINK_DIR}/${GNAT_PKGBASE}/|${BUILDLINK_DIR}/|g"

pkgbase := adawebserver-25
.include "../../mk/pkg-build-options.mk"

.endif

BUILDLINK_TREE+=	-adawebserver-25
