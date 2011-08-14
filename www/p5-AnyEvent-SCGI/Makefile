# $NetBSD: Makefile,v 1.3 2011/08/14 16:05:41 obache Exp $

DISTNAME=	AnyEvent-SCGI-1.1
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=AnyEvent/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/AnyEvent-SCGI/
COMMENT=	Perl 5 module providing a event based SCGI server
LICENSE=	${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/AnyEvent/SCGI/.packlist
PERL5_MODULE_TYPE=	Module::Install

DEPENDS+=	p5-AnyEvent>=5.2:../../devel/p5-AnyEvent
# Recommended
#DEPENDS+=	p5-Coro>=5.17:../../devel/p5-Coro
#DEPENDS+=	p5-EV-[0-9]*:../../devel/p5-EV

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
