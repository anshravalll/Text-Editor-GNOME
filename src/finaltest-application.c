/* finaltest-application.c
 *
 * Copyright 2023 Ansh
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#include "config.h"

#include "finaltest-application.h"
#include "finaltest-window.h"

struct _FinaltestApplication
{
	AdwApplication parent_instance;
};

G_DEFINE_TYPE (FinaltestApplication, finaltest_application, ADW_TYPE_APPLICATION)

FinaltestApplication *
finaltest_application_new (const char        *application_id,
                           GApplicationFlags  flags)
{
	g_return_val_if_fail (application_id != NULL, NULL);

	return g_object_new (FINALTEST_TYPE_APPLICATION,
	                     "application-id", application_id,
	                     "flags", flags,
	                     NULL);
}

static void
finaltest_application_activate (GApplication *app)
{
	GtkWindow *window;

	g_assert (FINALTEST_IS_APPLICATION (app));

	window = gtk_application_get_active_window (GTK_APPLICATION (app));

	if (window == NULL)
		window = g_object_new (FINALTEST_TYPE_WINDOW,
		                       "application", app,
		                       NULL);

	gtk_window_present (window);
}

static void
finaltest_application_class_init (FinaltestApplicationClass *klass)
{
	GApplicationClass *app_class = G_APPLICATION_CLASS (klass);

	app_class->activate = finaltest_application_activate;
}






static void
finaltest_application_init (FinaltestApplication *self)
{


  gtk_application_set_accels_for_action (GTK_APPLICATION (self),
                                         "win.open",
                                         (const char *[]) {
                                           "<Ctrl>o",
                                           NULL,
                                         });
}

