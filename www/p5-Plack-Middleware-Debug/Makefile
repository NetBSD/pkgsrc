# $NetBSD: Makefile,v 1.8 2013/12/09 14:17:55 obache Exp $

DISTNAME=	Plack-Middleware-Debug-0.14
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Plack/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Plack-Middleware-Debug/
COMMENT=	Plack middleware to display information on request/response
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Plack/Middleware/Debug/.packlist
PERL5_MODULE_TYPE=	Module::Install::Bundled

DEPENDS+=	p5-Class-Method-Modifiers>=1.05:../../devel/p5-Class-Method-Modifiers
DEPENDS+=	p5-Data-Dump-[0-9]*:../../devel/p5-Data-Dump
DEPENDS+=	p5-File-ShareDir>=1.00:../../devel/p5-File-ShareDir
DEPENDS+=	p5-Plack-[0-9]*:../../www/p5-Plack
DEPENDS+=	p5-Text-MicroTemplate-[0-9]*:../../textproc/p5-Text-MicroTemplate
DEPENDS+=	{perl>=5.10.1,p5-parent-[0-9]*}:../../devel/p5-parent
DEPENDS+=	p5-Module-Versions>=0.01:../../devel/p5-Module-Versions

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
