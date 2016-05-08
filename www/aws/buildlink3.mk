# $NetBSD: buildlink3.mk,v 1.1.42.1 2016/05/08 16:54:10 bsiegert Exp $

BUILDLINK_TREE+=	aws

.if !defined(AWS_BUILDLINK3_MK)
AWS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.aws+=	aws>=2.10.0.1
BUILDLINK_PKGSRCDIR.aws?=	../../www/aws

pkgbase := aws
.include "../../mk/pkg-build-options.mk"

.include "../../devel/zlib/buildlink3.mk"
.include "../../devel/gnatpython/buildlink3.mk"
.include "../../devel/gprbuild-aux/buildlink3.mk"
.endif	# AWS_BUILDLINK3_MK

BUILDLINK_TREE+=	-aws
