# $NetBSD: Makefile,v 1.5 2006/02/05 23:11:27 joerg Exp $
#

DISTNAME=	WWW-Curl-2.0
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=WWW/}

MAINTAINER=	imil@gcu.info
HOMEPAGE=	http://curl.haxx.se/libcurl/perl/
COMMENT=	Perl binding interface for curl

DEPENDS+=	curl>=7.12.1:../../www/curl

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=	auto/WWW/Curl/.packlist

.include "../../www/curl/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
