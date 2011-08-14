# $NetBSD: Makefile,v 1.9 2011/08/14 16:06:07 obache Exp $

DISTNAME=	Starman-0.2006
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Plack/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Starman/
COMMENT=	High-performance preforking PSGI web server
LICENSE=	${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# empty
PERL5_PACKLIST= auto/Starman/.packlist

DEPENDS+=	p5-Net-Server-SS-PreFork-[0-9]*:../../net/p5-Net-Server-SS-PreFork
DEPENDS+=	p5-Server-Starter-[0-9]*:../../sysutils/p5-Server-Starter
DEPENDS+=	p5-Data-Dump-[0-9]*:../../devel/p5-Data-Dump
DEPENDS+=	p5-libwww-[0-9]*:../../www/p5-libwww
DEPENDS+=	p5-HTTP-Parser-XS-[0-9]*:../../www/p5-HTTP-Parser-XS
DEPENDS+=	p5-Net-Server>=0.91:../../net/p5-Net-Server
DEPENDS+=	p5-Plack>=0.9931:../../www/p5-Plack
DEPENDS+=	p5-parent-[0-9]*:../../devel/p5-parent

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
