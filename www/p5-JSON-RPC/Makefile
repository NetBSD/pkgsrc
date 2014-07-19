# $NetBSD: Makefile,v 1.3 2014/07/19 14:26:07 wiz Exp $

DISTNAME=	JSON-RPC-1.03
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=JSON/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/JSON-RPC/
COMMENT=	JSON RPC 2.0 Server implementation for Perl
LICENSE=	${PERL5_LICENSE}

PKG_INSTALLATION_TYPES=	overwrite pkgviews
USE_TOOLS+=	perl:run

DEPENDS+=	p5-Class-Accessor-Lite-[0-9]*:../../devel/p5-Class-Accessor-Lite
DEPENDS+=	p5-HTTP-Daemon-[0-9]*:../../www/p5-HTTP-Daemon
DEPENDS+=	p5-libwww-[0-9]*:../../www/p5-libwww
DEPENDS+=	p5-JSON-[0-9]*:../../converters/p5-JSON
DEPENDS+=	p5-Plack-[0-9]*:../../www/p5-Plack
DEPENDS+=	p5-Router-Simple-[0-9]*:../../www/p5-Router-Simple
DEPENDS+=	p5-JSON-XS-[0-9]*:../../converters/p5-JSON-XS

PERL5_PACKLIST=	auto/JSON/RPC/.packlist
PERL5_MODULE_TYPE=	Module::Install::Bundled

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
