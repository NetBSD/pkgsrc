# $NetBSD: Makefile,v 1.1.1.1 2008/10/31 11:50:42 abs Exp $

DISTNAME=	Catalyst-Plugin-AutoRestart-0.92
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Catalyst/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/perldoc?Catalyst::Plugin::AutoRestart
COMMENT=	Restart Catalyst when specified memory threshold reached

DEPENDS+=	p5-Catalyst-Runtime>=5.7007:../../www/p5-Catalyst-Runtime
DEPENDS+=	p5-Class-C3>=0.19:../../devel/p5-Class-C3
DEPENDS+=	p5-Class-Data-Accessor>=0:../../devel/p5-Class-Data-Accessor
DEPENDS+=	p5-Text-SimpleTable>=0.03:../../textproc/p5-Text-SimpleTable
DEPENDS+=	p5-Proc-ProcessTable>=0.41:../../devel/p5-Proc-ProcessTable

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Catalyst/Plugin/AutoRestart/.packlist

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
