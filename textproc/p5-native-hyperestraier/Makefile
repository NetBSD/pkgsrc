# $NetBSD: Makefile,v 1.15 2015/06/12 10:51:40 wiz Exp $
#

.include "../../textproc/hyperestraier/Makefile.common"

PKGNAME=	p5-native-hyperestraier-1.0.0.${HYPERESTRAIER_VERSION}
PKGREVISION=	7
CATEGORIES=	databases perl5

COMMENT=	Perl native interface of Hyper Estraier
LICENSE=	gnu-lgpl-v2.1

CONFLICTS+=	p5-hyperestraier-[0-9]*

MY_SUBDIR=	perlnative
BUILD_DIRS=	${MY_SUBDIR}
CONFIGURE_DIRS=	${MY_SUBDIR}

GNU_CONFIGURE=	yes
USE_TOOLS+=	perl
PERL5_CONFIGURE=no
TEST_TARGET=	check

PERL5_PACKLIST= auto/Estraier/.packlist
REPLACE_PERL=	${MY_SUBDIR}/estcmd.pl

.include "../../textproc/hyperestraier/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
