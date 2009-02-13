# $NetBSD: Makefile,v 1.1.1.1 2009/02/13 16:51:59 abs Exp $

DISTNAME=	Catalyst-Plugin-Server-0.24
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Catalyst/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/perldoc?Catalyst::Plugin::Server
COMMENT=	Base Server plugin for RPC-able protocols

DEPENDS+=	p5-Catalyst-Runtime>=5.66:../../www/p5-Catalyst-Runtime
DEPENDS+=	p5-RPC-XML>=1.35:../../net/p5-RPC-XML

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Catalyst/Plugin/Server/.packlist

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
