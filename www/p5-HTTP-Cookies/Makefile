# $NetBSD: Makefile,v 1.1.1.1 2011/07/10 12:42:52 spz Exp $
#

DISTNAME=	HTTP-Cookies-6.00
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=HTTP/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/HTTP-Cookies/
COMMENT=	HTTP cookie jars
LICENSE=	${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-HTTP-Message>=6.02:../../www/p5-HTTP-Message

PERL5_PACKLIST=		auto/HTTP/Cookies/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
