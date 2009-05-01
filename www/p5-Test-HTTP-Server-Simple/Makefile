# $NetBSD: Makefile,v 1.3 2009/05/01 20:02:42 sno Exp $

DISTNAME=	Test-HTTP-Server-Simple-0.10
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Test/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Test-HTTP-Server-Simple/
COMMENT=	Perl 5 module providing Test::More functions for HTTP::Server::Simple
LICENSE=	gnu-gpl-v2 # OR artistic

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# empty
PERL5_PACKLIST= auto/Test/HTTP/Server/Simple/.packlist

DEPENDS+=	p5-HTTP-Server-Simple-[0-9]*:../../www/p5-HTTP-Server-Simple
# This may be only a build dependency - No, it's not
DEPENDS+=	p5-Test-Simple>0.62:../../devel/p5-Test-Simple

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
