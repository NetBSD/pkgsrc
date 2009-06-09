# $NetBSD: Makefile,v 1.12 2009/06/09 12:49:20 wiz Exp $
#

DISTNAME=	WWW-Curl-4.07
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=WWW/}

MAINTAINER=	imil@gcu.info
HOMEPAGE=	http://search.cpan.org/dist/WWW-Curl/
COMMENT=	Perl binding interface for curl

DEPENDS+=	curl>=7.10.8:../../www/curl

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=	auto/WWW/Curl/.packlist

.include "../../www/curl/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
