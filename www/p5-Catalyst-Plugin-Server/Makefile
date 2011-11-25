# $NetBSD: Makefile,v 1.8 2011/11/25 08:14:37 hiramatsu Exp $

DISTNAME=	Catalyst-Plugin-Server-0.28
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Catalyst/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Catalyst-Plugin-Server/
COMMENT=	Base Server plugin for RPC-able protocols
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Catalyst-Runtime>=5.66:../../www/p5-Catalyst-Runtime
DEPENDS+=	p5-RPC-XML>=0.67:../../net/p5-RPC-XML
DEPENDS+=	p5-MRO-Compat-[0-9]*:../../devel/p5-MRO-Compat
DEPENDS+=	p5-Clone-Fast-[0-9]*:../../devel/p5-Clone-Fast

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Catalyst/Plugin/Server/.packlist

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
