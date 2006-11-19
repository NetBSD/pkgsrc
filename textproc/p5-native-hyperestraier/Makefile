# $NetBSD: Makefile,v 1.2 2006/11/19 01:18:02 obache Exp $
#

.include "../../textproc/hyperestraier/Makefile.common"

PKGNAME=	p5-hyperestraier-1.0.0.${HYPERESTRAIER_VERSION}
CATEGORIES=	databases perl5
PKGREVISION=	1

COMMENT=	Perl interface of Hyper Estraier

MY_SUBDIR=	perlnative
BUILD_DIRS=	${MY_SUBDIR}
CONFIGURE_DIRS=	${MY_SUBDIR}

GNU_CONFIGURE=	yes
PERL5_CONFIGURE=no
TEST_TARGET=	check

PERL5_PACKLIST= auto/Estraier/.packlist
REPLACE_PERL=	${MY_SUBDIR}/estcmd.pl

.include "../../textproc/hyperestraier/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
