# $NetBSD: buildlink3.mk,v 1.4 2019/11/18 18:34:10 ng0 Exp $

BUILDLINK_TREE+=	gnurl

.if !defined(GNURL_BUILDLINK3_MK)
GNURL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gnurl+=	gnurl>=7.63.0
BUILDLINK_ABI_DEPENDS.gnurl+=	gnurl>=7.64.0nb1
BUILDLINK_PKGSRCDIR.gnurl?=	../../www/gnurl

pkgbase:= gnurl
.include "../../mk/pkg-build-options.mk"

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libidn2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../security/gnutls/buildlink3.mk"
.endif # GNURL_BUILDLINK3_MK

BUILDLINK_TREE+=	-gnurl
