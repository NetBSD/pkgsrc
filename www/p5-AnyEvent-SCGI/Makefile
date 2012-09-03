# $NetBSD: Makefile,v 1.4 2012/09/03 11:16:26 sno Exp $

DISTNAME=	AnyEvent-SCGI-1.1
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=AnyEvent/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/AnyEvent-SCGI/
COMMENT=	Perl 5 module providing a event based SCGI server
LICENSE=	${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/AnyEvent/SCGI/.packlist
PERL5_MODULE_TYPE=	Module::Install::Bundled

DEPENDS+=	p5-AnyEvent>=5.2:../../devel/p5-AnyEvent
# Recommended
#DEPENDS+=	p5-Coro>=5.17:../../devel/p5-Coro
#DEPENDS+=	p5-EV-[0-9]*:../../devel/p5-EV

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
