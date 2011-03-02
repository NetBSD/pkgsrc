# $NetBSD: buildlink3.mk,v 1.1 2011/03/02 10:14:31 drochner Exp $

BUILDLINK_TREE+=	aws

.if !defined(AWS_BUILDLINK3_MK)
AWS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.aws+=	aws>=2.10.0.1
BUILDLINK_PKGSRCDIR.aws?=	../../www/aws

.include "../../devel/zlib/buildlink3.mk"
.include "../../devel/gnatpython/buildlink3.mk"
.include "../../devel/gprbuild-aux/buildlink3.mk"
.endif	# AWS_BUILDLINK3_MK

BUILDLINK_TREE+=	-aws
