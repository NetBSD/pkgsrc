# $NetBSD: Makefile,v 1.4 2011/08/12 09:25:47 obache Exp $

DISTNAME=	HTTP-Date-6.00
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=HTTP/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/HTTP-Date/
COMMENT=	Perl 5 module providing date conversion routines
LICENSE=	${PERL5_LICENSE}

CONFLICTS+=	p5-libwww<6.00

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# empty
PERL5_PACKLIST= auto/HTTP/Date/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
