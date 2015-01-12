# $NetBSD: Makefile,v 1.16 2015/01/12 07:37:07 mef Exp $

DISTNAME=		HTTP-Lite-2.43
# Preparing if next release is 2.5 (rather than 2.50, use 2.4.3)
PKGNAME=		p5-${DISTNAME:C/([0-9])\.([0-9])([0-9]*)/\1.\2.\3/}
CATEGORIES=		www perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=HTTP/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/HTTP-Lite/
COMMENT=		Lightweight HTTP client implementation
LICENSE=		${PERL5_LICENSE}

PERL5_PACKLIST=		auto/HTTP/Lite/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
