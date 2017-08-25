# $NetBSD: buildlink3.mk,v 1.2 2017/08/25 16:49:15 jperkin Exp $

BUILDLINK_TREE+=	go-toml-pelletier

.if !defined(GO_TOML_PELLETIER_BUILDLINK3_MK)
GO_TOML_PELLETIER_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-toml-pelletier=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-toml-pelletier?=		build

BUILDLINK_API_DEPENDS.go-toml-pelletier+=		go-toml-pelletier>=1.0.0
BUILDLINK_PKGSRCDIR.go-toml-pelletier?=		../../www/go-toml-pelletier

.include "../../devel/go-buffruneio/buildlink3.mk"
.endif  # GO_TOML_PELLETIER_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-toml-pelletier
