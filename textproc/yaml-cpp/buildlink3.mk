# $NetBSD: buildlink3.mk,v 1.2 2018/01/07 13:04:36 rillig Exp $
#

BUILDLINK_TREE+=	yaml-cpp

.if !defined(YAML_CPP_BUILDLINK3_MK)
YAML_CPP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.yaml-cpp+=	yaml-cpp>=0.5.0
BUILDLINK_PKGSRCDIR.yaml-cpp?=		../../textproc/yaml-cpp

.include "../../devel/boost-headers/buildlink3.mk"
.endif	# YAML_CPP_BUILDLINK3_MK

BUILDLINK_TREE+=	-yaml-cpp
