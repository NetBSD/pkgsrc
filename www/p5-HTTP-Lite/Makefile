# $NetBSD: Makefile,v 1.1.1.1 2006/08/22 21:46:13 minskim Exp $

DISTNAME=		HTTP-Lite-2.1.6
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5hl
CATEGORIES=		www perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=HTTP/}

MAINTAINER=		eric@cirr.com
HOMEPAGE=		http://search.cpan.org/dist/HTTP-Lite/
COMMENT=		Lightweight HTTP client implementation

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/HTTP/Lite/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
