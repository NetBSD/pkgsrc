# $NetBSD: Makefile,v 1.3 2011/08/14 16:05:52 obache Exp $

DISTNAME=	Corona-0.1004
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
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
