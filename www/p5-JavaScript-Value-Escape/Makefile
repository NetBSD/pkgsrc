# $NetBSD: Makefile,v 1.3 2012/10/28 06:30:43 asau Exp $
#

DISTNAME=	JavaScript-Value-Escape-0.06
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=JavaScript/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/JavaScript-Value-Escape/
COMMENT=	Avoid XSS with JavaScript value interpolation
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/JavaScript/Value/Escape/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
