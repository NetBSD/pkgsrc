# $NetBSD: Makefile,v 1.25 2019/08/11 13:24:59 wiz Exp $

DISTNAME=	Starman-0.4014
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	4
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Plack/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Starman
COMMENT=	High-performance preforking PSGI web server
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=	# empty
PERL5_PACKLIST= auto/Starman/.packlist
PERL5_MODULE_TYPE=	Module::Build::Tiny

DEPENDS+=	p5-Net-Server-SS-PreFork-[0-9]*:../../net/p5-Net-Server-SS-PreFork
DEPENDS+=	p5-Server-Starter-[0-9]*:../../sysutils/p5-Server-Starter
DEPENDS+=	p5-Data-Dump-[0-9]*:../../devel/p5-Data-Dump
DEPENDS+=	p5-libwww-[0-9]*:../../www/p5-libwww
DEPENDS+=	p5-HTTP-Parser-XS-[0-9]*:../../www/p5-HTTP-Parser-XS
DEPENDS+=	p5-Net-Server>=0.91:../../net/p5-Net-Server
DEPENDS+=	p5-Plack>=0.9931:../../www/p5-Plack
#DEPENDS+=	{perl>=5.10.1,p5-parent-[0-9]*}:../../devel/p5-parent

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
