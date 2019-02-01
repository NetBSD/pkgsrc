# $NetBSD: buildlink3.mk,v 1.1 2019/02/01 15:21:29 gdt Exp $

BUILDLINK_TREE+=	gnurl

.if !defined(GNURL_BUILDLINK3_MK)
GNURL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gnurl+=	gnurl>=7.63.0
BUILDLINK_PKGSRCDIR.gnurl?=	../../www/gnurl

pkgbase:= gnurl
.include "../../mk/pkg-build-options.mk"

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.endif # GNURL_BUILDLINK3_MK

BUILDLINK_TREE+=	-gnurl
