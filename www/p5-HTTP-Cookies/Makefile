# $NetBSD: Makefile,v 1.3 2011/08/07 08:52:12 tron Exp $

DISTNAME=	HTTP-Cookies-6.00
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=HTTP/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/HTTP-Cookies/
COMMENT=	HTTP cookie jars
LICENSE=	${PERL5_LICENSE}

CONFLICTS+=	p5-libwww-[0-5]*

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-HTTP-Message>=6.02:../../www/p5-HTTP-Message

PERL5_PACKLIST=		auto/HTTP/Cookies/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
