# $NetBSD: Makefile,v 1.4 2011/08/14 16:06:04 obache Exp $

DISTNAME=	Net-FastCGI-0.12
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	www perl5 net
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Net/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Net-FastCGI/
COMMENT=	Perl 5 module to build and parse FastCGI messages
LICENSE=	${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# empty
PERL5_PACKLIST= auto/Net/FastCGI/.packlist

BUILD_DEPENDS+=	p5-Test-Exception-[0-9]*:../../devel/p5-Test-Exception
BUILD_DEPENDS+=	p5-Test-HexString-[0-9]*:../../devel/p5-Test-HexString

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
