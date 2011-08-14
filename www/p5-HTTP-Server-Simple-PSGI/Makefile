# $NetBSD: Makefile,v 1.3 2011/08/14 16:05:59 obache Exp $

DISTNAME=	HTTP-Server-Simple-PSGI-0.14
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=HTTP/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/HTTP-Server-Simple-PSGI/
COMMENT=	PSGI handler for HTTP::Server::Simple
LICENSE=	${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# empty
PERL5_PACKLIST= auto/HTTP/Server/Simple/PSGI/.packlist

DEPENDS+=	p5-HTTP-Server-Simple>=0.42:../../www/p5-HTTP-Server-Simple

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
