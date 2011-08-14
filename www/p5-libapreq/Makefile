# $NetBSD: Makefile,v 1.24 2011/08/14 16:06:12 obache Exp $

DISTNAME=	libapreq-1.34
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
SVR4_PKGNAME=	p5lap
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Apache/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://httpd.apache.org/apreq/
COMMENT=	Lots of Apache specific httpd handling modules
LICENSE=	apache-2.0

PKG_DESTDIR_SUPPORT=	user-destdir

MAKE_JOBS_SAFE=		no

DEPENDS+=	p5-Apache-Test>=1.13:../../www/p5-Apache-Test

USE_LANGUAGES=	c
PERL5_PACKLIST=	auto/libapreq/.packlist

LDFLAGS+=	${COMPILER_RPATH_FLAG}auto/libapreq

.include "../../lang/perl5/module.mk"
.include "../../www/ap-perl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
