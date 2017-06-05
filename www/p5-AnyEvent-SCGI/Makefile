# $NetBSD: Makefile,v 1.12 2017/06/05 14:25:07 ryoon Exp $

DISTNAME=	AnyEvent-SCGI-1.1
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	9
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=AnyEvent/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/AnyEvent-SCGI/
COMMENT=	Perl 5 module providing a event based SCGI server
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/AnyEvent/SCGI/.packlist
PERL5_MODULE_TYPE=	Module::Install::Bundled
MAKE_ENV+=		PERL5_CPANPLUS_IS_RUNNING=1

DEPENDS+=	p5-AnyEvent>=5.2:../../devel/p5-AnyEvent
# Recommended
#DEPENDS+=	p5-Coro>=5.17:../../devel/p5-Coro
#DEPENDS+=	p5-EV-[0-9]*:../../devel/p5-EV

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
