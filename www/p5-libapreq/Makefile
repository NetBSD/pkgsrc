# $NetBSD: Makefile,v 1.20 2008/10/19 19:19:17 he Exp $

DISTNAME=	libapreq-1.33
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	5
SVR4_PKGNAME=	p5lap
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Apache/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://httpd.apache.org/apreq/
COMMENT=	Lots of Apache specific httpd handling modules

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-Apache-Test>=1.13:../../www/p5-Apache-Test

USE_LANGUAGES=	c
PERL5_PACKLIST=	auto/libapreq/.packlist

LDFLAGS+=	${COMPILER_RPATH_FLAG}auto/libapreq

.include "../../lang/perl5/module.mk"
.include "../../www/ap-perl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
