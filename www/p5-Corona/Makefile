# $NetBSD: Makefile,v 1.2 2010/08/21 16:36:45 seb Exp $

DISTNAME=	Corona-0.1004
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Plack/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Corona/
COMMENT=	Perl 5 Coro based PSGI web server
LICENSE=	${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# empty
PERL5_PACKLIST= auto/Corona/.packlist

DEPENDS+=	p5-Coro-[0-9]*:../../devel/p5-Coro
DEPENDS+=	p5-Net-Server-Coro>=0.5:../../net/p5-Net-Server-Coro
DEPENDS+=	p5-Plack>=0.99:../../www/p5-Plack

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
