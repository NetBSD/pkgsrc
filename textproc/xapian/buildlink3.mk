# $NetBSD: buildlink3.mk,v 1.3 2011/12/03 03:44:38 sbd Exp $

BUILDLINK_TREE+=	xapian

.if !defined(XAPIAN_BUILDLINK3_MK)
XAPIAN_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.xapian+=	xapian>=1.0.7
BUILDLINK_ABI_DEPENDS.xapian?=	xapian>=1.2.2nb1
BUILDLINK_PKGSRCDIR.xapian?=	../../textproc/xapian

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Linux" || ${OPSYS} == "SunOS"
.include "../../devel/libuuid/buildlink3.mk"
.endif
.include "../../devel/zlib/buildlink3.mk"

.endif # XAPIAN_BUILDLINK3_MK

BUILDLINK_TREE+=	-xapian
