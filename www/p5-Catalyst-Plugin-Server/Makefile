# $NetBSD: Makefile,v 1.7 2011/08/14 16:05:49 obache Exp $

DISTNAME=	Catalyst-Plugin-Server-0.24
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	4
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Catalyst/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/perldoc?Catalyst::Plugin::Server
COMMENT=	Base Server plugin for RPC-able protocols

BROKEN=		Catalyst::Plugin::Server must not be used with RPC::XML>0.67

DEPENDS+=	p5-Catalyst-Runtime>=5.66:../../www/p5-Catalyst-Runtime
DEPENDS+=	p5-RPC-XML>=0.64:../../net/p5-RPC-XML
#DEPENDS+=	p5-RPC-XML<=0.67:../../net/p5-RPC-XML

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Catalyst/Plugin/Server/.packlist

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
