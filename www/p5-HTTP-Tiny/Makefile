# $NetBSD: Makefile,v 1.1.1.1 2011/11/15 12:57:14 sno Exp $
#

DISTNAME=	HTTP-Tiny-0.016
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=HTTP/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/HTTP-Tiny/
COMMENT=	Perl5 module providing a small, simple, correct HTTP/1.1 client
LICENSE=	${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/HTTP/Tiny/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
