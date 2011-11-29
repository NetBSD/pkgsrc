# $NetBSD: Makefile,v 1.1.1.1 2011/11/29 10:39:24 hiramatsu Exp $
#

DISTNAME=	JavaScript-Value-Escape-0.06
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=JavaScript/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/JavaScript-Value-Escape/
COMMENT=	Avoid XSS with JavaScript value interpolation
LICENSE=	${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir
PERL5_PACKLIST=		auto/JavaScript/Value/Escape/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
