# $NetBSD: Makefile,v 1.6 2018/11/04 18:38:09 bsiegert Exp $

DISTNAME=	hugo-0.26
PKGNAME=	go-${DISTNAME}
PKGREVISION=	4
MASTER_SITES=	${MASTER_SITE_GITHUB:=gohugoio/}
CATEGORIES=	www
GITHUB_TAG=	v${PKGVERSION_NOREV}
GITHUB_PROJECT= ${PKGBASE:S/^go-//}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://gohugo.io/
COMMENT=	A Fast & Modern Static Website Engine
LICENSE=	apache-2.0

GO_DIST_BASE=	${DISTNAME}
GO_SRCPATH=	github.com/gohugoio/hugo

REPLACE_SH+=	bench.sh
REPLACE_SH+=	benchSite.sh
REPLACE_SH+=	pull-docs.sh

.include "../../devel/go-purell/buildlink3.mk"
.include "../../textproc/go-inflect/buildlink3.mk"
.include "../../devel/go-amber/buildlink3.mk"
.include "../../devel/go-fsnotify/buildlink3.mk"
.include "../../net/go-websocket/buildlink3.mk"
.include "../../devel/go-osext/buildlink3.mk"
.include "../../devel/go-emoji/buildlink3.mk"
.include "../../textproc/go-mmark/buildlink3.mk"
.include "../../devel/go-mapstructure/buildlink3.mk"
.include "../../devel/go-blackfriday/buildlink3.mk"
.include "../../devel/go-afero/buildlink3.mk"
.include "../../devel/go-cast/buildlink3.mk"
.include "../../devel/go-cobra/buildlink3.mk"
.include "../../devel/go-fsync/buildlink3.mk"
.include "../../devel/go-jwalterweatherman/buildlink3.mk"
.include "../../devel/go-nitro/buildlink3.mk"
.include "../../devel/go-pflag/buildlink3.mk"
.include "../../devel/go-viper/buildlink3.mk"
.include "../../www/go-ace/buildlink3.mk"
.include "../../textproc/go-text/buildlink3.mk"
.include "../../devel/go-yaml/buildlink3.mk"
.include "../../devel/go-gitmap/buildlink3.mk"
.include "../../devel/go-goorgeous/buildlink3.mk"
.include "../../www/go-cssmin/buildlink3.mk"
.include "../../devel/go-immutable-radix/buildlink3.mk"
.include "../../textproc/go-prose/buildlink3.mk"
.include "../../devel/go-i18n/buildlink3.mk"
.include "../../graphics/go-image/buildlink3.mk"
.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"

